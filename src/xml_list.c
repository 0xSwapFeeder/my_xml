/*
** EPITECH PROJECT, 2020
** xml_node_list.c
** File description:
** header for xml_node_list.c
*/

#include <stdlib.h>
#include "my_xml.h"

int xmlnode_list_init(xmlnode_list_t *list)
{
    list->size = 0;
    list->h_size = 1;
    list->data = malloc(sizeof(xmlnode_t *) * list->h_size);
    if (list->data == NULL)
        return 0;
    return 1;
}

int xmlnode_add(xmlnode_t *add, xmlnode_list_t *list)
{
    while (list->size >= list->h_size) {
        list->h_size *= 2;
        list->data = mem_expand(list->data, sizeof(xmlnode_t *) * list->size,
        sizeof(xmlnode_t *) * list->h_size);
        if (list->data == NULL)
            return 0;
    }
    list->data[list->size++] = add;
    return 1;
}

int xmlattr_list_init(xmlattr_list_t *list)
{
    list->size = 0;
    list->h_size = 1;
    list->data = malloc(sizeof(xml_attribute_t) * list->h_size);
    if (list->data == NULL)
        return 0;
    return 1;
}

int xmlattribute_add(xml_attribute_t *add, xmlattr_list_t *list)
{
    while (list->size >= list->h_size) {
        list->h_size *= 2;
        list->data = mem_expand(list->data,
        sizeof(xml_attribute_t) * list->size,
        sizeof(xml_attribute_t) * list->h_size);
        if (list->data == NULL)
            return 0;
    }
    list->data[list->size++] = *add;
    return 1;
}
