NAME = e.schwartz-resume
VERSION = 0.2.0

.PHONY: all build tag_latest push push_latest run last_built_date

all: build

build:
	docker build -t $(NAME):$(VERSION) --rm .

tag_latest:
	docker tag -f $(NAME):$(VERSION) $(NAME):latest

push:
	docker push $(NAME):$(VERSION)

push_latest:
	docker push $(NAME):latest

run:
	if [[ "$(docker images -q $(NAME):$(VERSION) 2> /dev/null)" == "" ]]; then
		docker run -it $(NAME):$(VERSION) /bin/bash
	fi

last_built_date:
	docker inspect -f '{{ .Created }}' $(NAME):$(VERSION)
