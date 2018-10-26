#!/bin/bash
file = "$HOME/.bashrc" # match + longo com */
echo "File path: $file" #retira a partir do inicio match + longo com */
echo "File name: ${file##*/}"
echo "Directory name: ${file%/*}" # retirar a partir do match + curto com */
