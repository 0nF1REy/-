#!/usr/bin/env bash

set -e

if ! command -v pacman >/dev/null 2>&1; then
  echo "Este script é compatível apenas com Arch Linux e derivados!"
  exit 1
fi

echo "==> Instalando pacotes oficiais (pacman)..."
sudo pacman -S --needed - < pacman.txt

if command -v yay >/dev/null 2>&1; then
  echo "==> Instalando pacotes AUR / foreign (yay)..."
  yay -S --needed - < aur.txt
else
  echo "yay não está instalado!"
fi

echo "Instalação concluída!"
