#include <stdio.h>
#include <string.h>

#include "nJson.h"

int main(int argc, char** argv){

    nJson* photo_info = 0;
    nJson* contents = 0;
    nJson* json = 0;

    {
        double lat_long[2] = {37.77256666666666, -122.45934166666667};
        char* time_taken = "Wed, 28 Aug 2013 18:12:02 +0000";

        photo_info = nJson_init(photo_info, "Interno", "lat_long", lat_long,
            sizeof(lat_long), 1, sizeof(lat_long)/sizeof(double),
            nJson_writeDouble);

        nJson_setData(photo_info, "time_taken", time_taken,
            strlen(time_taken)+1, 0, 1, nJson_writeString);
    }

    {
        char* size = "2.3 MB";
        char* rev = "38af1b183490";
        char thumb_exists = 1;
        unsigned bytes = 2453963;
        char* modified = "Mon, 07 Apr 2014 23:13:16 +0000";
        char* client_mtime = "Thu, 29 Aug 2013 01:12:02 +0000";
        char* path = "/Photos/flower.jpg";
        char is_dir = 0;
        char* icon = "page_white_picture";
        char* root = "dropbox";
        char* mime_type = "image/jpeg";
        unsigned revision = 14511;

        contents = nJson_init(contents, "Contenido", "size", size,
            strlen(size)+1, 0, 1, nJson_writeString);

        nJson_setData(contents, "rev", rev,
            strlen(rev)+1, 0, 1, nJson_writeString);

        nJson_setData(contents, "thumb_exists", &thumb_exists,
            sizeof(char), 0, 1, nJson_writeBoolean);

        nJson_setData(contents, "bytes", &bytes,
            sizeof(unsigned), 0, 1, nJson_writeUnsigned);

        nJson_setData(contents, "modified", modified,
            strlen(modified)+1, 0, 1, nJson_writeString);

        nJson_setData(contents, "client_mtime", client_mtime,
            strlen(client_mtime)+1, 0, 1, nJson_writeString);

        nJson_setData(contents, "path", path,
            strlen(path)+1, 0, 1, nJson_writeString);

        nJson_setData(contents, "photo_info", photo_info,
            sizeof(nJson), 0, 1, nJson_writenJson);

        nJson_setData(contents, "is_dir", &is_dir,
            sizeof(char), 0, 1, nJson_writeBoolean);

        nJson_setData(contents, "icon", icon,
            strlen(icon)+1, 0, 1, nJson_writeString);

        nJson_setData(contents, "root", root,
            strlen(root)+1, 0, 1, nJson_writeString);

        nJson_setData(contents, "mime_type", mime_type,
            strlen(mime_type)+1, 0, 1, nJson_writeString);

        nJson_setData(contents, "revision", &revision,
            sizeof(unsigned), 0, 1, nJson_writeUnsigned);
    }

    unsigned bytes = 0;
    char* hash = "37eb1ba1849d4b0fb0b28caf7ef3af52";
    char* size = "0 bytes";
    char thumb_exists = 0;
    char* rev = "714f029684fe";
    char* modified = "Wed, 27 Apr 2011 22:18:51 +0000";
    char* path = "/Photos";
    char is_dir = 1;
    char* icon = "folder";
    char* root = "dropbox";
    unsigned revision = 29007;

    json = nJson_init(json, "Ejemplo", "size", size,
        strlen(size)+1, 0, 1, nJson_writeString);

    nJson_setData(json, "hash", hash,
        strlen(hash)+1, 0, 1, nJson_writeString);

    nJson_setData(json, "bytes", &bytes,
        sizeof(unsigned), 0, 1, nJson_writeUnsigned);

    nJson_setData(json, "thumb_exists", &thumb_exists,
        sizeof(char), 0, 1, nJson_writeBoolean);

    nJson_setData(json, "rev", rev,
        strlen(rev)+1, 0, 1, nJson_writeString);

    nJson_setData(json, "modified", modified,
        strlen(modified)+1, 0, 1, nJson_writeString);

    nJson_setData(json, "path", path,
        strlen(path)+1, 0, 1, nJson_writeString);

    nJson_setData(json, "is_dir", &is_dir,
        sizeof(char), 0, 1, nJson_writeBoolean);

    nJson_setData(json, "icon", icon,
        strlen(icon)+1, 0, 1, nJson_writeString);

    nJson_setData(json, "rev", rev,
        strlen(rev)+1, 0, 1, nJson_writeString);

    nJson_setData(json, "root", root,
        strlen(root)+1, 0, 1, nJson_writeString);

    nJson_setData(json, "contents", contents,
        sizeof(nJson), 1, 1, nJson_writenJson);

    nJson_setData(json, "revision", &revision,
        sizeof(unsigned), 0, 1, nJson_writeUnsigned);

    FILE* file = (argc==3 && !strcmp(argv[1], "-f")) ? fopen(argv[2], "w+")
        : stdout;

    nJson_writenJson(file, json);
    nJson_endWrite(file);
    nJson_free(photo_info);
    nJson_free(contents);
    nJson_free(json);
    return 0;
}
