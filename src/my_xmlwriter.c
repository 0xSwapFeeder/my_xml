/*
** EPITECH PROJECT, 2020
** my_xmlwriter.c
** File description:
** header for my_xmlwriter.c
*/

#include <bits/types/FILE.h>
#include <stdio.h>
#include "my_xml.h"

int my_fstrlen(const char *str)
{
    int i = 0;

    while (str && str[i])
        i++;
    return i;
}

void attributes(xmlnode_t *node, FILE *file)
{
    char *key;
    char *value;

    if (node->attributes.size > 0) {
        for (int i = 0; i < node->attributes.size; i++) {
            key = node->attributes.data[i].key;
            value = node->attributes.data[i].value;
            fwrite(" ", 1, sizeof(char), file);
            fwrite(key, my_fstrlen(key), sizeof(char), file);
            fwrite("=", 1, sizeof(char), file);
            fwrite("\"", 1, sizeof(char), file);
            fwrite(value, my_fstrlen(value), sizeof(char), file);
            fwrite("\"", 1, sizeof(char), file);
        }
    }
}

void closing_tag(xmlnode_t *node, FILE *file, int tab_count)
{
    char *tab = "\t";

    if (tab_count > 0 && !node->data) {
        for (int i = 0; i < tab_count - 1; i++)
            fwrite(tab, 1, sizeof(char), file);
    }
    fwrite("</", 2, sizeof(char), file);
    fwrite(node->tag, my_fstrlen(node->tag), sizeof(char), file);
    fwrite(">\n", 2, sizeof(char), file);
}

void xml_write(xmlnode_t *node, FILE *file, int tab_count)
{
    if (tab_count > 0) {
        for (int i = 0; i < tab_count; i++)
            fwrite("\t", 1, sizeof(char), file);
    }
    fwrite("<", 1, sizeof(char), file);
    fwrite(node->tag, my_fstrlen(node->tag), sizeof(char), file);
    attributes(node, file);
    fwrite(">", 1, sizeof(char), file);
    if (node->data)
        fwrite(node->data, my_fstrlen(node->data), sizeof(char), file);
    else
        fwrite("\n", 1, sizeof(char), file);
    tab_count++;
    if (node->children.size > 0) {
        for (int i = 0; i < node->children.size; i++) {
            xml_write(node->children.data[i], file, tab_count);
        }
    }
    closing_tag(node, file, tab_count);
}

void write_xmldoc(xmldoc_t *doc, char *path)
{
    FILE *newfile = fopen(path, "w");
    xmlnode_t *node = doc->root;

    if (newfile == NULL)
        return;
    xml_write(node, newfile, 0);
}