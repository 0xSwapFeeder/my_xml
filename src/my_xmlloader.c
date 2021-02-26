/*
** EPITECH PROJECT, 2020
** my_xmlloader.c
** File description:
** header for my_xmlloader.c
*/

#include "my_xml.h"

char *extract_data_untilchar(xml_reader_t *reader, char c)
{
    while (reader->source[reader->i] && reader->source[reader->i] != c) {
        reader->lex[reader->idx++] = reader->source[reader->i++];
    }
    reader->lex[reader->idx] = '\0';
    return my_strndup(reader->lex, reader->idx);
}

int parse_node(xml_reader_t *reader)
{
    if (reader->source[reader->i] == '<') {
        reader->lex[reader->idx] = '\0';
        get_xml_data_tag(reader);
        if (check_close(reader))
            return 1;
        else if (reader->i != 0)
            reader->curr = create_new_xmlnode(reader->curr);
        reader->i++;
        if (!reader->curr || !write_tag(reader))
            return 0;
        return 1;
    }
    return -1;
}

int iterate_xml_doc(xml_reader_t *reader)
{
    int good;

    for (reader->i = 0; reader->source[reader->i] != '\0'; ) {
        good = parse_node(reader);
        if (good == 1)
            continue;
        else if (!good)
            return 0;
        else
            reader->lex[reader->idx++] = reader->source[reader->i++];
    }
    return 1;
}

xmldoc_t *load_xmldoc(char *path)
{
    xmldoc_t *doc = malloc(sizeof(xmldoc_t));
    xml_reader_t reader;
    int good;

    reader.source = load_file(path);
    reader.idx = 0;
    doc->root = create_new_xmlnode(NULL);
    if (doc == NULL || reader.source == NULL || doc->root == NULL) {
        my_putstr_err("Error creating doc or reading doc file\n");
        return NULL;
    } doc->path = path;
    reader.curr = doc->root;
    good = iterate_xml_doc(&reader);
    if (!good) {
        free(reader.source);
        free_xmlnode(doc->root);
        return NULL;
    }
    free(reader.source);
    return doc;
}

int main(void)
{
    xmldoc_t *doc = load_xmldoc("write_test.xml");


    write_xmldoc(doc, "write_test_fromcopy.xml");
    free_xmlnode(doc->root);
    free(doc);
}