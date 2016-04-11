#!/bin/bash

#
# Thanks to ewhitt for his bash script for installing dependencies. Source:
# http://stackoverflow.com/questions/28868681/bash-script-to-install-dependencies-and-provide-status-feedback
#

dep_ubuntu="libopencv-dev zlib1g-dev"

length=$(echo $dep_ubuntu | wc -w)

for pkg in $dep_ubuntu; do
    echo "Installing ${pkg}..."
    sudo apt-get install --yes ${pkg}
done