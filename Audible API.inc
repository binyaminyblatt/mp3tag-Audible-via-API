# Audible via API Tag Source for Mp3tag
#
# Initial release by Florian.
# See CHANGELOG.md for a list of changes.

[Name]=Audible API
[WordSeperator]=+
[IndexFormat]=%_coverurl%|%_preview%|%_url%|%Album%|%Author%|%Narrator%|%Duration%|%Year%|%Language%
[Settings]=A&udible API#Settings….settings
[Encoding]=url-utf-8
[MinAppVersionMac]=1.8.6
[MinAppVersionWin]=3.22
[Version]=0.5.9

[ParserScriptIndex]=...
#debug "on" "audible-api-index.txt"

replace "|" "$verticalBar()"
json "ON" "current"

json_select "total_results"
IfNot "0"
    json_foreach "products"
        json_select_object "product_images"
        json_select "100"
        SayRest
        json_unselect_object
        Say "|"

        json_select "asin"
        # need to fix this to work with all regions
        Say "https://www.audible.com/pd/"
        SayRest
        Say "|"

        json_select "asin"
        SayRest
        Say "?response_groups=category_ladders,contributors,media,product_desc,product_attrs,product_extended_attrs,rating,series,product_details&image_sizes=1000,500,100"
        Say "|"

        json_select "title"
        RegexpReplace "(.*?) \(Narrated by .*" "$1"
        SayRest
        Say "|"

        json_select_many "authors" "name" ", "
        SayRest
        Say "|"

        json_select_many "narrators" "name" ", "
        SayRest
        Say "|"

        json_select "runtime_length_min"
        SayDuration "m" 1
        Say "|"

        json_select "release_date"
        SayRest
        Say "|"

        json_select "language"
        SayRest

        SayNewLine
    json_foreach_end
EndIf


[ParserScriptAlbum]=...
#debug "on" "audible-api-album.txt"

replace "|" "$verticalBar()"

json "ON" "current"
json_select_object "product"

OutputTo "coverurl"
json_select_object "product_images"
json_select "1000"
IfNot ""
    SayRest
Else
    json_select "500"
    IfNot ""
        SayRest
    Else
        json_select "100"
        SayRest
    EndIf
EndIf
json_unselect_object

OutputTo "ASIN"
json_select "asin"
SayRest

OutputTo "ALBUM"
json_select "title"
RegexpReplace "(.*?) \(Narrated by .*" "$1"
SayRest

OutputTo "SUBTITLE"
json_select "subtitle"
SayRest

OutputTo "LANGUAGE"
json_select "language"
SayRest

OutputTo "COPYRIGHT"
json_select "copyright"
SayRest

OutputTo "EXPLICIT"
json_select "is_adult_product"
SayRest

OutputTo "ABRIDGED"
json_select "format_type"
SayRest

OutputTo "ISBN"
json_select "isbn"
SayRest


# This is the code i edited since plex cant handle multple ALBUMARTIST's i moved it to ALBUMARTISTS and ALBUMARTIST is just the first author 
# i added the setting singleAlbumArtist to make the to make ALBUMARTIST the first author for plex like apps and set the default to false for backwards compatibility
IfVar "singleAlbumArtist" "true"
    OutputTo "ALBUMARTISTS"
    json_select_many "authors" "name" ", "
    SayRest

    OutputTo "ALBUMARTIST"
    json_foreach "authors"
        IfNotOutput "ALBUMARTIST"
            json_select "name"
            SayRest
        EndIf
    json_foreach_end
Else
    OutputTo "ALBUMARTIST"
    json_select_many "authors" "name" ", "
    SayRest
EndIf

OutputTo "COMPOSER"
json_select_many "narrators" "name" ", "
SayRest

json_select_many_count "series"
IfNot ""
    OutputTo "SHOWMOVEMENT"
    say "1"

    OutputTo "SERIES"
    json_select_array "series" 1
    json_select "title"
    SayRest

    OutputTo "SERIES-PART"
    json_select "sequence"
    SayRest

    json_unselect_object

    OutputTo "CONTENTGROUP"
    SayOutput "SERIES"
    Say ", Book #"
    SayOutput "SERIES-PART"

    OutputTo "ALBUMSORT"
    SayOutput "SERIES"
    Say " "
    SayOutput "SERIES-PART"
    Say " - "
    SayOutput "ALBUM"
Else
    IfNotOutput "SUBTITLE"
        OutputTo "ALBUMSORT"
        SayOutput "ALBUM"
    Else
        OutputTo "ALBUMSORT"
        SayOutput "ALBUM"
        Say " - "
        SayOutput "SUBTITLE"
    EndIf
Endif


KillTag "GENRE"
KillTag "TMP_GENRE1"
KillTag "TMP_GENRE2"
OutputTo "GENRE"
json_foreach "category_ladders"
IfVar "singleGenre" "true"
    json_foreach "ladder"
        IfNotOutput "GENRE"
            json_select "name"
            SayRest
        Else
			IfNotOutput "TMP_GENRE1"
				OutputTo "TMP_GENRE1"
				json_select "name"
				SayRest
			Else
				IfNotOutput "TMP_GENRE2"
					OutputTo "TMP_GENRE2"
					json_select "name"
					SayRest
        EndIf
			EndIf
		EndIf
    json_foreach_end
Else
    IfOutput "GENRE"
        IfVar "delimiter" "\\\\"
            Say "\\\\"
        EndIf
        IfVar "delimiter" ", "
            Say ", "
        EndIf
        IfVar "delimiter" ";"
            Say ";"
        EndIf
        IfVar "delimiter" "/"
            Say "/"
        EndIf
        IfVar "delimiter" "|"
            Say "$verticalBar()"
        EndIf
        IfVar "delimiter" " "
            Say " "
        EndIf
    EndIf
    json_select_many "ladder" "name" " / "
    SayRest
EndIf
json_foreach_end
json_select_object "product"

OutputTo "RATING"
json_select_object "rating"
json_select_object "overall_distribution"
json_select "display_average_rating"
SayRest
json_unselect_object
json_unselect_object

OutputTo "RATING WMP"
SayOutput "RATING"

OutputTo "COMMENT"
json_select "publisher_summary"
KillTag "*"
Unspace
RegexpReplace "  +" " "
Replace " ," ","
SayRest

OutputTo "PUBLISHER"
json_select "publisher_name"
SayRest

OutputTo "YEAR"
json_select "release_date"
SayNChars 4

OutputTo "RELEASETIME"
json_select "release_date"
SayRest

OutputTo "ARTIST"
IfVar  "singleAlbumArtist" "true"
    SayOutput "ALBUMARTISTS"
Else
    SayOutput "ALBUMARTIST"
EndIf
IfVar "narratorInArtist" "true"
    Say ", "
    SayOutput "COMPOSER"
EndIf

OutputTo "DESCRIPTION"
SayOutput "COMMENT"

OutputTo "ITUNESMEDIATYPE"
Say "Audiobook"

OutputTo "ITUNESGAPLESS"
Say "1"

OutputTo "MOVEMENTNAME"
SayOutput "SERIES"

OutputTo "MOVEMENT"
SayOutput "SERIES-PART"


OutputTo "WWWAUDIOFILE"
json "OFF"
RegexpReplace "^.*" "%CurrentUrl%"
RegexpReplace ".*api\.audible\.(.+?)\/.*" "https://www.audible.$1/pd/"
SayRest
SayOutput "ASIN"