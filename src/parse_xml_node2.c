/*
** EPITECH PROJECT, 2020
** parse_xml_node2.c
** File description:
** header for parse_xml_node2.c
*/

#include "my_xml.h"

int check_write_tag_loop(xml_reader_t *reader)
{
    int good = get_xml_tag(reader);

    if (!good)
        return 0;
    else if (good == 1)
        return 1;
    good = get_xml_attribute(reader);
    if (!good)
        return 0;
    else if (good == 1)
        return 1;
    return -1;
}