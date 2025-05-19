# Changelog — Audible API Tag Source for Mp3tag

## 0.6.1 (2025-05-16) @Florian
- Changed to filter non-author roles (e.g., translators) from list of authors.

## 0.6.0 (2025-05-15) @bblatt @Florian
- Added support for field `COPYRIGHT`.
- Added support for field `EXPLICIT` and `ITUNESADVISORY`.
- Added support for field `FORMAT`.
- Added support for field `ISBN`.
- Added support for field `LANGUAGE`.
- Added support for field `RATING WMP`.
- Added configuration setting to use first album artist only and store complete list in `ALBUMARTISTS`.
- Added importing of additional genres to `TMP_GENRE1` and `TMP_GENRE2` if first genre only is stored in `GENRE`.
- Added Tag Sources for audible.co.jp
- Added Tag Sources for audible.com.au
- Added Tag Sources for audible.com.br
- Added Tag Sources for audible.es
- Added Tag Sources for audible.it
- Added Tag Sources to directly search by filename.
- Changed to write `TMP_GENRE1` and `TMP_GENRE2` if single genre only configuration setting is enabled.
- Fixed preview URL to use locale-specific URL.
- Removed code duplication in Search by ASIN Tag Sources.
- Added README

## 0.5.0 (2025-04-16) @Florian
- Added Tag Sources for audible.ca
- Added Tag Sources for audible.fr
- Fixed `WWWAUDIOFILE` to use locale-specific URL.

## 0.4.0 (2024-12-29) @Florian
- Added Tag Sources for audible.co.uk

## 0.3.0 (2024-11-06) @Florian

- Added Tag Source to directly search by ASIN.
- Added column for Narrator to query results.
- Fixed multiple series and parts were concatenated into one string.

## 0.2.1 (2024-05-25) @Florian

- Fixed no results opened confirmation dialog with static fields.

## 0.2.0 (2024-05-24) @Florian

- Added dedicated preview URL instead of opening API result.

## 0.1.0 (2024-04-09) @Florian

- Initial release.