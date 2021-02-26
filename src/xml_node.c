/*
** EPITECH PROJECT, 2020
** xml_node.c
** File description:
** header for xml_node.c
*/

#include "my_xml.h"
#include <stdlib.h>

xmlnode_t *create_new_xmlnode(xmlnode_t *parent)
{
    xmlnode_t *new = malloc(sizeof(xmlnode_t));

    if (new == NULL)
        return NULL;

    new->parent = parent;
    new->data = NULL;
    new->tag = NULL;
    xmlattr_list_init(&new->attributes);
    xmlnode_list_init(&new->children);
    if (parent)
        xmlnode_add(new, &parent->children);
    return new;
}

void xmlattr_list_free(xmlattr_list_t *list)
{
    for (int i = 0; i < list->size; i++) {
        free(list->data[i].value);
        free(list->data[i].key);
    }
    if (list->data)
        free(list->data);
}

void free_xmlnode(xmlnode_t *node)
{
    if (node->tag)
        free(node->tag);
    if (node->data)
        free(node->data);
    xmlattr_list_free(&node->attributes);
    if (node->children.size > 0) {
        for (int i = 0; i < node->children.size; i++)
            free_xmlnode(node->children.data[i]);
    }
    if (node->children.data)
        free(node->children.data);
    free(node);
}