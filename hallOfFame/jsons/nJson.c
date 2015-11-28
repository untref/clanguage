#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "nJson.h"

Data* data_hasData (Data* this, char* name) {
    if (this) return strcmp (this->name, name) ?
                    data_hasData (this->next, name) : this;
    return NULL;
}

Data* data_addData(Data* this, char* name, void* value, unsigned size,
                    char isArray, unsigned length, Write func) {
    if (!this) {
        this = malloc (sizeof (Data));
        this->name = strcpy (malloc (strlen (name)+1), name);
        this->value = memcpy (malloc (size), value, size);
        this->isArray = isArray;
        this->length = length;
        this->func = func;
        this->next = NULL;
    }
    else this->next = data_addData (this->next, name, value, size, isArray,
                    length, func);
    return this;
}

void data_freeData(Data* this){
    if (this) {
        free (this->name);
        this->name = NULL;
        free (this->value);
        this->value = NULL;
        free (this);
        data_freeData (this = this->next);
    }
}

nJson* nJson_init (nJson* this, char* name, char* attrName, void* value,
                                unsigned size, char isArray, unsigned length,
                                    Write func) {
    nJson_checkValue (value);
    this = malloc (sizeof (nJson));
    this->name = strcpy (malloc (strlen (name)+1), name);
    this->data = NULL;
    nJson_setData (this, attrName, value, size, isArray, length, func);
    return this;
}

void nJson_setName (nJson* this, char* name) {
    nJson_checknJson (this);
    free(this->name);
    this->name = strcpy (malloc (strlen (name)+1), name);
}

char nJson_hasData (nJson* this, char* name) {
    nJson_checknJson (this);
    return data_hasData (this->data, name) ? '1' : '0';
}

void nJson_setData (nJson* this, char* name, void* value, unsigned size,
                                char isArray, unsigned length, Write func) {
    nJson_checknJson (this);
    nJson_checkValue (value);
    nJson_checkLength (length);
    Data* temp = data_hasData (this->data, name);
    if (!temp) this->data = data_addData (this->data, name, value, size,
            isArray, length, func);
    else {
        free (temp->value);
        temp->value = memcpy (malloc (size), value, size);
        temp->isArray = isArray;
        temp->length = length;
        temp->func = func;
    }
}

void nJson_writeData (FILE* file, nJson* this, char* name) {
    nJson_checkFile (file);
    nJson_checknJson (this);
    Data* data = data_hasData (this->data, name);
    nJson_checkData (data);
    fprintf (file, "\"%s\":", data->name);
    if (data->isArray) fprintf (file, "[");
    void* temp = data->value;
    int i;
    for (i = 0; i < data->length; i++) temp = data->func (file, temp);
    if (data->isArray) {
        nJson_eraseLastCharacter (file);
        fprintf (file, "],");
    }
}

void* nJson_writeInt (FILE* file, void* value) {
    nJson_checkFile (file);
    nJson_checkValue (value);
    fprintf (file, "%d,", *(int*)value);
    return value += sizeof (int);
}

void* nJson_writeUnsigned (FILE* file, void* value) {
    nJson_checkFile (file);
    nJson_checkValue (value);
    fprintf (file, "%u,", *(unsigned*)value);
    return value += sizeof (unsigned);
}

void* nJson_writeDouble (FILE* file, void* value) {
    nJson_checkFile (file);
    nJson_checkValue (value);
    fprintf (file, "%f,", *(double*)value);
    return value += sizeof (double);
}

void* nJson_writeLong (FILE* file, void* value) {
    nJson_checkFile (file);
    nJson_checkValue (value);
    fprintf (file, "%ld,", *(long*)value);
    return value += sizeof (long);
}

void* nJson_writeFloat (FILE* file, void* value) {
    nJson_checkFile (file);
    nJson_checkValue (value);
    fprintf (file, "%f,", *(float*)value);
    return value += sizeof (float);
}

void* nJson_writeShort (FILE* file, void* value) {
    nJson_checkFile (file);
    nJson_checkValue (value);
    fprintf (file, "%d,", *(short*)value);
    return value += sizeof (short);
}

void* nJson_writeUnsignedShort (FILE* file, void* value) {
    nJson_checkFile (file);
    nJson_checkValue (value);
    fprintf (file, "%u,", *(short*)value);
    return value += sizeof (short);
}

void* nJson_writeString (FILE* file, void* value) {
    nJson_checkFile (file);
    nJson_checkValue (value);
    fprintf (file, "\"%s\",", (char*)value);
    return value += strlen ((char*)value)+1;
}

void* nJson_writeBoolean(FILE* file, void* value) {
    nJson_checkFile(file);
    nJson_checkValue(value);
    *(char*)value ? fprintf(file, "true,") : fprintf(file, "false,");
    return value += sizeof (char);
}

void* nJson_writenJson(FILE* file, void* this) {
    nJson* json = (nJson*)this;
    nJson_checkFile (file);
    nJson_checknJson (json);
    fprintf (file, "{");
    Data* data = json->data;
    nJson_checkData (data);
    do nJson_writeData (file, json, data->name); while ((data = data->next));
    nJson_eraseLastCharacter (file);
    fprintf (file, "},");
    return this += sizeof (nJson);
}

void nJson_checknJson (nJson* this) { if (!this) exit(1); }

void nJson_checkData (Data* this) { if (!this) exit(2); }

void nJson_checkFile (FILE* this) { if (!this) exit(3); }

void nJson_checkValue (void* this) { if (!this) exit(4); }

void nJson_checkLength (unsigned this) { if (!this) exit(5); }

void nJson_eraseLastCharacter (FILE* file) {
    nJson_checkFile (file);
    (file == stdout) ? fprintf (file, "\b") : fseek (file, -1, SEEK_END);
}

void nJson_endWrite (FILE* file) {
    nJson_checkFile (file);
    nJson_eraseLastCharacter (file);
    fprintf (file, " ");
    fclose (file);
}

char* nJson_getError (int id) {
    switch (id) {
        case 1: return "Error: JSON no válido.";
        case 2: return "Error: dato no válido.";
        case 3: return "Error: archivo no válido.";
        case 4: return "Error: valor no válido.";
        case 5: return "Error: longitud no válida.";
        default: return "Error desconocido.";
    }
}

void nJson_free (nJson* this) {
    nJson_checknJson (this);
    data_freeData (this->data);
    this->data = NULL;
    free (this->name);
    this->name = NULL;
    free (this);
}
