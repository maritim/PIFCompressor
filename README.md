PIF Compressor
==========

Researching task to check a new compression method for images.

Test results
------------

| Image         | Input size    | Output size    | Compression rate |
| ------------- |:-------------:|:--------------:|:----------------:|
| autumn.tif    | 1.113.530 B   | 878.908 B  	 | 21.08 %	        |
| duck.tif      | 2.393.502 B   | 1.838.986 B	 | 23.17 %	        |
| bears.tif     | 1.883.242 B   | 1.443.865 B    | 23.30 %	        |

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
        ./PIFCompressor.out --decompress output/lenna.pif --output output/lenna2.tif
        
