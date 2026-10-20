#ifndef DATA_H
#define DATA_H
#include <stdbool.h>
#include <stddef.h>

typedef struct DataObject DataObject;
typedef struct DataArray DataArray;

typedef enum ValueTypeTag {
  VALUE_NULL,
  VALUE_BOOL,
  VALUE_INTEGER,
  VALUE_FLOAT,
  VALUE_STRING,
  VALUE_ARRAY,
  VALUE_OBJECT,
} ValueTypeTag;

typedef union ValueTypeData {
  bool Bool;
  int Integer;
  float Float;
  char* String;
  DataArray* Array;
  DataObject* Object;
} ValueTypeData;

typedef struct DataObjectEntry {
  char* key;
  ValueTypeData data;
  ValueTypeTag tag;
} DataObjectEntry;

typedef struct DataObject {
  DataObjectEntry* entries;
  size_t size;
  size_t capacity;
} DataObject;

typedef struct DataArray {
  ValueTypeData* data;
  ValueTypeTag tag;
  size_t size;
  size_t capacity;
} DataArray;

typedef struct DataNode {
  ValueTypeTag tag;
  ValueTypeData data;
  DataNode* children;
  DataNode* sibling;
} DataNode;

#endif