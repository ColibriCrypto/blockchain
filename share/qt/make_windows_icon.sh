#!/bin/bash
# create multiresolution windows icon
# 
ICON_SRC=../../src/qt/res/icons/CLBI.png
ICON_DST=../../src/qt/res/icons/CLBI.ico
convert ${ICON_SRC} -resize 16x16 CLBI-16.png
convert ${ICON_SRC} -resize 32x32 CLBI-32.png
convert ${ICON_SRC} -resize 48x48 CLBI-48.png
convert CLBI-16.png CLBI-32.png CLBI-48.png ${ICON_DST}
# 
ICON_SRC=../../src/qt/res/icons/CLBI_mainet.png
ICON_DST=../../src/qt/res/icons/CLBI_mainet.ico
convert ${ICON_SRC} -resize 16x16 CLBI-16.png
convert ${ICON_SRC} -resize 32x32 CLBI-32.png
convert ${ICON_SRC} -resize 48x48 CLBI-48.png
convert CLBI-16.png CLBI-32.png CLBI-48.png ${ICON_DST}
rm CLBI-16.png CLBI-32.png CLBI-48.png
