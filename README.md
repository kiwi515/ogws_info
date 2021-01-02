# ogws_info
Resources/information that I've gathered during my work with OGWS.  
  
If you are interested in the decompilation, or would like to contribute, feel free to check it out here: https://github.com/doldecomp/ogws
  
## Index
- `RSPE_r1.dmap`: Symbol map (NTSC-U, v1.01) for use with the Dolphin emulator, to aid in debugging. Converted from the decompilation Ghidra project. Updated when I get the chance.  
  
- `RSPE_r1.map`: Symbol map (NTSC-U, v1.01) for use with Ghidra when loading the Wii Sports DOL.  
  
- `RSPE_r1.csv`: Symbol map (NTSC-U, v1.01) in CSV form, for whatever data analysis you may want to do.
  
## Instructions
Dolphin is a bit confusing with this stuff, so I thought I'd leave a note here.  
Dolphin will only look for `{install-directory}\User\Maps\{GameID}.map` if you select `Symbols > Load Symbol Map`, so you need to instead select `Symbols > Load Other Map File...`, and navigate the to the `*.dmap` file you have downloaded.
