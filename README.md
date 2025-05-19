# Audible API Tag Source for Mp3tag

This Audible Tag Source allows for searching audiobooks via the external Audible API.

## Download

https://community.mp3tag.de/t/ws-audible-via-api/64347

## Source

https://github.com/fheidenreich/mp3tag-tag-sources/

## Installation

Requires Mp3tag v3.22 or Mp3tag for Mac v1.8.6.

### Windows

In Mp3tag, use **File → Open configuration folder** and extract the contents of the downloaded archive to `data\sources\`.

### macOS

In Mp3tag, use **Tag Sources → Open Tag Sources Folder** and extract the contents of the downloaded archive.


## Supported Fields

| Mp3tag            | Audible                                                            |
| ----------------- | ------------------------------------------------------------------ |
| `ALBUM`           | Title                                                              |
| `ALBUMARTIST`     | Author                                                             |
| `ALBUMARTISTS`    | List of authors                                                    |
| `ALBUMSORT`       | If `ALBUM` only, then *Title*, if `ALBUM` and `SUBTITLE`, then *Title - Subtitle*, if `SERIES`, then *Series Series-Part - Title* |
| `ARTIST`          | Author, Narrator                                                   |
| `ASIN`            | Amazon Standard Identification Number                              |
| `COMMENT`         | Publisher's Summary (MP3)                                          |
| `COMPOSER`        | Narrator                                                           |
| `CONTENTGROUP`    | Series, Book #                                                     |
| `COPYRIGHT`       | Copyright                                                          |
| `DESCRIPTION`     | Publisher's Summary (M4B)                                          |
| `EXPLICIT`        | Set to `1` if adult content                                        |
| `FORMAT`          | Format type, e.g., `unabridged`                                    |
| `GENRE`           | Genre1/Genre2 (using the configured delimiter for multiple values) |
| `ISBN`            | International Standard Book Number                                 |
| `ITUNESADVISORY`  | Set to `1` if adult content, `2` if clean (M4B)                    |
| `ITUNESGAPLESS`   | M4B Gapless album = 1                                              |
| `ITUNESMEDIATYPE` | M4B Media type = Audiobook                                         |
| `LANGUAGE`        | Language                                                           |
| `MOVEMENT`        | Series Book #                                                      |
| `MOVEMENTNAME`    | Series                                                             |
| `PUBLISHER`       | Publisher                                                          |
| `RATING WMP`      | Audible Rating (MP3)                                               |
| `RATING`          | Audible Rating                                                     |
| `RELEASETIME`     | Audiobook Release Date                                             |
| `SERIES-PART`     | Series Book #                                                      |
| `SERIES`          | Series                                                             |
| `SHOWMOVEMENT`    | M4B Movement, if Series then set to `1` otherwise left out         |
| `SUBTITLE`        | Subtitle                                                           |
| `TMP_GENRE1`      | Genre 1 (if single genre only configuration setting is enabled)    |
| `TMP_GENRE2`      | Genre 2 (if single genre only configuration setting is enabled)    |
| `WWWAUDIOFILE`    | Audible Album URL                                                  |
| `YEAR`            | Audiobook Release Year                                             |

I've tried to be as compatible to the existing Audible Tag Sources as possible. Let me know if there is something missing or can be changed to improve compatibility with existing systems.

## Configuration Settings

### Add narrator to artist
If enabled, the narrator is added to the artist field.

### Add single album artist only
If enabled and the audiobook has multiple artists, only the first artist is added to the `ALBUMARTIST` field and the complete list of artists is stored in `ALBUMARTISTS`.

### Add single genre only
If enabled and the audiobook has multiple genres, only the first genre is added to the `GENRE` field and `TMP_GENRE1` and `TMP_GENRE2` have additional genres.

### Delimiter for multiple values
The string to use as a delimiter for multiple genres.
