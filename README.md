# My Resume

## Getting started

They are three different ways to see my resume, from the most classical to the most surprising one: PDF to C compiling or even using Docker containers. Let's get started!

## Prerequisites

Depending on the way you are going to choose to see my resume, some softwares are needed. For the PDF option, a regular PDF viewer is only needed.
Concerning the C option, the `gcc` compiler is needed. But most of the Linux distos already got pre-installed.
On the other hands, if you can't have access to a Linux machine, the docker image is made for you. This solution is multi-OS, and can be run from any machine as long as docker is installed on it.

## PDF - The classical way.

Please go to the folder named `pdf` and open the file *cv_emmanuel_schwartz* with your favourite PDF viewer.

## C - Compile to see it!
An original way to visit my resume
### Builing&Compiling ###
Go to the folder named`c`:
```
cd ./c
```
Then, compile with `gcc`:
```
gcc -W -Wall -o resume.exe resume.c
```
Checking all shared library dependencies with `ldd`:
```
ldd resume.exe
```
Finnally, launch my `resume.exe` to see my resume!
```
./resume.exe
```

## Docker - The multi-platform solution
Go to the folder named `docker`:
```
cd ./docker
```
Then, build the image:
```
sudo make
```
Finally, launch the container just created:
```
sudo docker run e.schwartz-resume:0.1.0
```
## Results

![alt tag](https://github.com/frenchieisverige/resume/blob/master/res/screenshot.png)

## Built With

* [latex](https://www.latex-project.org/) - The most popular document preparation system
* [modern-cv](https://www.google.de/search?client=ubuntu&channel=fs&q=gcccv-modern&ie=utf-8&oe=utf-8&gfe_rd=cr&ei=Fh43WcD5HM7PXoqruogP#channel=fs&q=modern+cv) - Popular CV template for Latex
* [gcc](https://gcc.gnu.org/) - The GNU Compiler Collection
* [docker](https://www.docker.com/) - The most famous software container platform

## Authors

* **FrenchieiSverige** - *Initial work* - [my-resume](https://github.com/frenchieisverige/)


