# 🧰 System Packages – Informações

Este diretório contém todos os arquivos necessários para **reproduzir o ambiente de desenvolvimento**
baseado em Arch Linux / EndeavourOS, além de registrar o estado do sistema.

---

## 📜 Arquivos

### 1️⃣ install.sh

Script para instalar os pacotes listados nos arquivos de texto.

```bash
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
```

### 2️⃣ pacman.txt

Lista de pacotes **oficiais** que serão instalados via pacman.

> Cada pacote está em uma linha separada.

### 3️⃣ aur.txt

Lista de pacotes **AUR / foreign** que serão instalados via yay.

> Cada pacote está em uma linha separada.

### 4️⃣ LOG.md

Arquivo de **registro do estado do sistema** no momento do snapshot.

- Contém informações sobre data, hora, usuário, hostname e contexto
- Serve como referência para reproduzir ou comparar estados anteriores do sistema
