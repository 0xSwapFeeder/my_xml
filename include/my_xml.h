/*
** EPITECH PROJECT, 2020
** my_xml_cl.h
** File description:
** header for my_xml_cl.c
*/

#ifndef MY_XML_MY_XML_H
#define MY_XML_MY_XML_H
#include <stdlib.h>

char *load_file(char *filepath);
char *my_strndup(char *src, int i);
int my_strcmp(const char *s1, const char *s2);
void my_putstr_err(char *str);
void my_memcpy(void *dest, void *src, size_t size);
void *mem_expand(void *data, size_t actual_size, size_t newsize);

typedef struct xml_attribute xml_attribute_t;
typedef struct xmlattr_list_s xmlattr_list_t;

typedef struct xml_node_s xmlnode_t;
typedef struct xmlnode_list_s xmlnode_list_t;

typedef struct xmldoc_s xmldoc_t;


struct xml_attribute {
    char *key;
    char *value;
};

struct xmlattr_list_s {
    int h_size;
    int size;
    xml_attribute_t *data;
};


struct xmlnode_list_s {
    int h_size;
    int size;
    xmlnode_t **data;
};

struct xml_node_s {
    char *tag;
    char *data;
    struct xml_node_s *parent;
    xmlattr_list_t attributes;
    xmlnode_list_t children;
};

struct xmldoc_s {
    xmlnode_t *root;
    char *source;
    char *path;
};

typedef struct xml_reader {
    char lex[1024];
    int idx;
    char *source;
    int i;
    xmlnode_t *curr;
    xml_attribute_t attr;
}xml_reader_t;

// xml reader
char *extract_data_untilchar(xml_reader_t *reader, char c);
int parse_node(xml_reader_t *reader);
xmldoc_t *load_xmldoc(char *path);
int check_close(xml_reader_t *reader);
int get_xml_attribute(xml_reader_t *reader);
int get_xml_tag(xml_reader_t *reader);
int get_xml_data_tag(xml_reader_t *reader);
int write_tag(xml_reader_t *reader);
int check_write_tag_loop(xml_reader_t *reader);

//xml node list
int xmlnode_list_init(xmlnode_list_t *list);
int xmlnode_add(xmlnode_t *add, xmlnode_list_t *list);

//xml attributes list
int xmlattr_list_init(xmlattr_list_t *list);
int xmlattribute_add(xml_attribute_t *add, xmlattr_list_t *list);
void xmlattr_list_free(xmlattr_list_t *list);

//xml node
xmlnode_t *create_new_xmlnode(xmlnode_t *parent);
void free_xmlnode(xmlnode_t *node);



void write_xmldoc(xmldoc_t *doc, char *path);

#endif //MY_XML_MY_XML_H
