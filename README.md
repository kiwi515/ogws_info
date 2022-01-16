
# OGWS Info

*Data gathered during my work with* ***[OGWS]*** *.*

##### Use

This repository is only meant to cover structures from **RP Engine**.

##### External Definitions

As the engine was designed for the `Pack Project`, the code references <br>
other external resources like `EGG` and `NW4R`, which are not defined here.

##### Virtual Addresses

As this project is designed to help future decompilation, all specified <br>
`Virtual Addresses` reference the `US Rev 1` version of the game.

##### Interest

*If you are interested in the decompilation or would* <br>
*like to contribute, feel free to check it out* ***[OGWS]*** *.*

---

## Overview

- [`RP/`][Code]

    `Documented Code` regarding data structures <br>
    as well as concepts in the **RP Engine**.

    *Most classes will only have headers,* <br>
    *but if the code is easily documentable* <br>
    *then it will usually also have a `CPP` file.*

    <br>

- [`RSPE_r1.dmap`][Symbols Dolphin] `NTSC-U` `v1.01`

    `Symbol Map` for use with the **Dolphin** <br>
    emulator, to aid in debugging.

    *Converted from the de-compiled Ghidra project.*

    *Updated when I get the chance.*

    <br>

- [`RSPE_r1.map`][Symbols Ghidra] `NTSC-U` `v1.01`

    `Symbol Map` for use with **Ghidra** <br>
    when loading the `Wii Sports DOL`.

    <br>

- [`RSPE_r1.csv`][Symbols CSV] `NTSC-U` `v1.01`

    `Symbol Map` in **CSV** form, for whatever <br>
    data analysis you may want to do.

---

## Instructions

***Dolphin*** *is a bit confusing with this stuff,* <br>
*so I thought I'd leave a note here.*

<br>

If you select `Symbols » Load Symbol Map` , **Dolphin** will only look <br>
for `<Installation Directory>\User\Maps\<Game Id>.map` files.


Instead select `Symbols » Load Other Map File ...` & <br>
navigate the to the `*.dmap` file you have downloaded.


<!---------------------------------------------------------------------------->

[OGWS]: https://github.com/doldecomp/ogws

[Code]: Source/RP/

[Symbols Dolphin]: Source/RSPE_r1.dmap
[Symbols Ghidra]: Source/RSPE_r1.map
[Symbols CSV]: Source/RSPE_r1.csv
