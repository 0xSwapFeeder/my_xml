/*
** EPITECH PROJECT, 2020
** parse_xml_node.c
** File description:
** header for parse_xml_node.c
*/

#include "my_xml.h"

int check_close(xml_reader_t *reader)
{
    char lex[1024];
    int idx = 0;

    if (reader->source[reader->i + 1] == '/') {
        reader->i += 2;
        while (reader->source[reader->i] != '>')
            lex[idx++] = reader->source[reader->i++];
        lex[idx] = '\0';
        if (!reader->curr)
            my_putstr_err("Already at the root\n");
        if (my_strcmp(reader->curr->tag, lex))
            my_putstr_err("Closing tag doesn't match\n");
        reader->curr = reader->curr->parent;
        (reader->i)++;
        return 1;
    }
    return 0;
}

int get_xml_attribute(xml_reader_t *reader)
{
    if (reader->source[reader->i] == '=') {
        reader->lex[reader->idx] = '\0';
        reader->attr.key = my_strndup(reader->lex, reader->idx);
        if (!reader->attr.key)
            return 0;
        reader->idx = 0;
        return 1;
    }
    if (reader->source[reader->i] == '"') {
        reader->idx = 0;
        reader->i++;
        reader->attr.value = extract_data_untilchar(reader, '"');
        if (!reader->attr.value ||
        !xmlattribute_add(&reader->attr, &reader->curr->attributes))
            return 0;
        reader->idx = 0;
        reader->i++;
        return 1;
    }
    return -1;
}

int get_xml_tag(xml_reader_t *reader)
{
    if (reader->source[reader->i] == ' ' && !reader->curr->tag) {
        reader->lex[reader->idx] = '\0';
        reader->curr->tag = my_strndup(reader->lex, reader->idx);
        if (!reader->curr->tag)
            return 0;
        reader->idx = 0;
        reader->i++;
        return 1;
    }
    if (reader->source[reader->i - 1] == ' ') {
        reader->idx--;
    }
    return -1;
}

int get_xml_data_tag(xml_reader_t *reader)
{
    if (reader->idx > 0 && !reader->curr->data && reader->lex[0] != '\n') {
        reader->curr->data = my_strndup(reader->lex, reader->idx);
        if (reader->curr->data == NULL)
            return 0;
        reader->idx = 0;
    } else if (reader->idx > 0 &&
    (reader->curr->data || reader->lex[0] == '\n'))
        reader->idx = 0;
    return 1;
}

int write_tag(xml_reader_t *reader)
{
    int good;

    while (reader->source[reader->i] != '>') {
        reader->lex[reader->idx++] = reader->source[reader->i++];
        good = check_write_tag_loop(reader);
        if (!good)
            return 0;
        else if (good == 1)
            continue;
    }
    reader->lex[reader->idx] = '\0';
    if (!reader->curr->tag) {
        reader->curr->tag = my_strndup(reader->lex, reader->idx);
        if (reader->curr->tag == NULL) {
            my_putstr_err("Error with my_strndup");
            return 0;
        }
    } reader->idx = 0;
    reader->i++;
    return 1;
}