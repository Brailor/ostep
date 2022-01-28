#! /bin/bash

echo "Provisioning Box..."

uname -a

apt-get update
apt-get install -y tmux

echo "---------------------"
echo "Creating directory for github repos:"
mkdir -p ~/repos/github.com

echo "Cloning dotfiles:"
# clone dotfiles repo
git clone https://github.com/Brailor/dotfiles.git ~/repos/github.com

echo "Create backups for default system dotfiles"
mv ~/.bashrc ~/.bashrc.backup

echo "Symlink dotfiles"
ln -s ~/repos/github.com/dotfiles/.bashrc ~/.bashrc

echo "Done"

