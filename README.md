# Terrain

The program was created with the purpose of generating scenarios with mountains for a 2D game, that through the midpoint displacement algorithm it is possible to create a line (1D) containing the heights of all points calculated from according to the two randomly defined endpoints, which is used to create a mesh (2D) containing mountains constructed randomly from a depth perspective. In addition, the program is able, through the algorithm already mentioned, to create up to three scenarios, representing each period of the day, with three mountains in different shades with celestial bodies to increase it, being possible also that the user choose via terminal desired period.

### Prerequisites

You will need to install the modules below to run the program: 
* [GCC 8.1 or greater](http://gcc.gnu.org/)

### Running

To run this software, we gonna compile in the terminal:
1. Enter the folder and compile all the .c files with the following command:
```
$ gcc main.c mapa.c montain.c -o main
```
2. Run the following command:
```
$ ./main -d <value> -o <file> 
```
An example would be:
```
$ ./main -d 256 -o montain.ppm
```
An example w
3. From this it only interacts with the system.

## Built With

* [Atom](https://atom.io/) - A code editor used

## Authors
### Developers: 
* **Luís Eduardo Anunciado Silva ([cruxiu@ufrn.edu.br](mailto:cruxiu@ufrn.edu.br))** 
* **Erick de Oliveira Silva ([erickos@ufrn.edu.br](mailto:erickos@ufrn.edu.br))** 
### Project Advisor: 
* **Andre Mauricio Cunha Campos ([andre@dimap.ufrn.br](mailto:andre@dimap.ufrn.br))** 

See also the list of [contributors](https://github.com/cruxiu/IMD0012-Terrain/contributors) who participated in this project.

## License

This project is licensed under the GPL 3.0 - see the [LICENSE](LICENSE) file for details
