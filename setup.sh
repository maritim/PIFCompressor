#!/bin/bash

#
# Thanks to ewhitt for his bash script for installing dependencies. Source:
# http://stackoverflow.com/questions/28868681/bash-script-to-install-dependencies-and-provide-status-feedback
#

# TODO: Extend for multiple Linux Distributions

function InstallDependency
{
	if [ -f /etc/debian_version ]; then
		sudo apt-get install --yes $1
	elif [ -f /etc/arch-release ]; then
		sudo pacman -S $1
	elif [ -f /etc/fedora-release ]; then
		sudo yum install $1
	else
		echo "The installation was interupted because there is no know package manager."
	fi
}

if [[ `uname` == "Linux" ]]; then
	dep_ubuntu="libopencv-dev zlib1g-dev"

	length=$(echo $dep_ubuntu | wc -w)

	for pkg in $dep_ubuntu; do
	    if hash ${pkg} 2>/dev/null; then
		    echo "Installing ${pkg}..."
		    InstallDependency ${pkg}
		else
			echo "${pkg} already installed. Do nothing."
		fi
	done

elif [[ `uname` == "Darwin"* ]]; then

	if hash brew 2>/dev/null; then
		echo /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
	fi

	dep_apple = "opencv zlib"

	length = $(echo $dep_apple | wc -w)

	for pkg in $dep_apple; do
	    if hash ${pkg} 2>/dev/null; then
		    echo "Installing ${pkg}..."
		    brew install --yes ${pkg}
		else
			echo "${pkg} already installed. Do nothing."
		fi
	done

fi
