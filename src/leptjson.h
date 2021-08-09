#include <stddef.h> /* size_t */

#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum {
    LEPT_NULL,
    LEPT_FALSE,
    LEPT_TRUE,
    LEPT_NUMBER,
    LEPT_STRING,
    LEPT_ARRAY,
    LEPT_OBJECT
}lept_type;

typedef struct {
    union {
        struct {
            char* content; size_t length;
        }string;
        double number;
    };
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR,
    LEPT_PARSE_NUMBER_TOO_BIG,
    LEPT_PARSE_MISS_QUOTATION_MARK,
    LEPT_PARSE_INVALID_STRING_ESCAPE,
    LEPT_PARSE_INVALID_STRING_CHAR
};

#define lept_set_null(value) lept_free(value)
#define lept_init(v) do { (v)->type = LEPT_NULL; }while(0)

int lept_parse(lept_value* value, const char* json);

lept_type lept_get_type(const lept_value* value);

double lept_get_number(const lept_value* value);
void lept_set_number(lept_value* value, double n);

int lept_get_boolean(lept_value* value);
void lept_set_boolean(lept_value* value, int b);

const char* lept_get_string(const lept_value* value);
size_t lept_get_string_length(const lept_value* value);
void lept_set_string(lept_value* value, const char* s, size_t len);

void lept_free(lept_value* value);

#endif /* LEPTJSON_H__ */