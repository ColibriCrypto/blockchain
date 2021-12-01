#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

CLBID=${CLBID:-$BINDIR/clbid}
CLBICLI=${CLBICLI:-$BINDIR/clbi-cli}
CLBITX=${CLBITX:-$BINDIR/clbi-tx}
CLBIQT=${CLBIQT:-$BINDIR/qt/clbi-qt}

[ ! -x $CLBID ] && echo "$CLBID not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
read -r -a clbiVER <<< "$($CLBICLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for CLBId if --version-string is not set,
# but has different outcomes for CLBI-qt and CLBI-cli.
echo "[COPYRIGHT]" > footer.h2m
$CLBID --version | sed -n '1!p' >> footer.h2m

for cmd in $CLBID $CLBICLI $CLBITX $CLBIQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${clbiVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${clbiVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
