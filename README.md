# my-resume

Three different ways to see my resume: *C*, *Docker* or *PDF* version. Choose the one that suit you the best.

## Getting started

Depending on the way you are going to choose to see my resume, some softwares are needed:
* *PDF*: a regular PDF viewer is only needed.
* *C*: The `gcc` compiler is needed. 
* *Docker*: This multi-OS solution can be run from any machine as long as Docker is installed on it.

## Run 
### PDF - The classical way.

Please go to the folder named `pdf` and open the file *cv_emmanuel_schwartz* with your favourite PDF viewer.

### C - Compile to see it!

Go to the folder named`c`:
```
cd ./c
```
Then, compile with `gcc`:
```
gcc  -o resume.exe resume.c
```
Launch my `resume.exe` to see my resume!
```
./resume.exe
```

### Docker - The multi-platform solution

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
sudo docker run e.schwartz-resume:0.2.0
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


