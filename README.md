PIF Compressor
==========

Researching task to check a new compression method for images.

Unix Install Guide
=================

Get the project from GitHub
--------------------

* Install git

        sudo apt-get install -y git

* Create a local directory for the project

        mkdir PIFCompressor && cd PIFCompressor
    
* Clone the project

        git clone https://github.com/maritim/PIFCompressor

Install and configure dependecies
--------------------

* Install dependecies

        sudo chmod +x setup.sh
        sudo ./setup.sh
    
Build
-----

* Compile the project

        make
        
* Run the application on a sample image

        ./PIFCompressor.out --compress input/lenna.tif --output output/lenna.pif
        ./PIFCompressor.out --decompress output/lenna.pif --output output/lenna2.pif
        
