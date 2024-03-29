# ogws_info
Resources/information that I've gathered during my work with *Wii Sports*.  
Everything is designed to work with Doxygen, the auto-generated documentation framework.  
- This repository is meant to only cover structures from the RP engine (the engine designed for the Pack Project). 
- As a result, this code will reference other external (EGG/NW4R/etc.) structures that are not defined here.  
- Because this project is designed to help future decompilation, all virtual addresses specified are for the US Rev 1 version of the game.  
  
If you are interested in the decompilation, or would like to contribute, feel free to check it out here: https://github.com/doldecomp/ogws
  
## Index
- `RP/`: Documented code regarding data structures and concepts in the RP engine. Most classes will only have headers, but if the code is easily documentable then it will usually also have a CPP file.
  
- `RSPE_r1.dmap`: Symbol map (NTSC-U, v1.01) for use with the Dolphin emulator, to aid in debugging. Converted from the decompilation Ghidra project. Updated when I get the chance.  
  
- `RSPE_r1.map`: Symbol map (NTSC-U, v1.01) for use with Ghidra when loading the Wii Sports DOL.  
  
- `RSPE_r1.csv`: Symbol map (NTSC-U, v1.01) in CSV form, for whatever data analysis you may want to do.
  
## Instructions
Dolphin will only look for `{install-directory}\User\Maps\{GameID}.map` if you select `Symbols > Load Symbol Map`, so you need to instead select `Symbols > Load Other Map File...`, and navigate the to the `*.dmap` file you have downloaded.
