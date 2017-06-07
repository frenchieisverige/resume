FROM ubuntu

MAINTAINER FrenchieiSverige

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install gcc mono-mcs && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /home/dev
ENV HOME /home/dev

COPY resume.c /home/dev/resume.c

RUN gcc -W -Wall -o resume.exe resume.c 

CMD ["/home/dev/resume.exe"]


