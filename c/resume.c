#include <stdio.h>
#include <time.h>

typedef struct {
	union {
		const char * company;
		const char * school;
		const char * project;
	};
	union {
		const char * location;
		const char * url;
	};
	union {
		const char * title;
		const char * program;
	};

	time_t started;
	time_t left;

	const char * description[];
} thing_t;

typedef thing_t job_t;
typedef thing_t school_t;
typedef thing_t project_t;

#define CURRENT 0 /* I wasn't alive at the Unix epoch, so that'll work */

/* Contact Information */
const char * name    = "Emmanuel SCHWARTZ";
const char * email   = "emmanuel.schwartz@netcourrier.com";
const char * address = "Senden, Germany";
                       

/* Education */
school_t uni_ger = {
	.school   = "University Applied of Science",
	.location = "Ulm, Germany",
	.program  = "Master Information Systems",
	.started  = 1412467200,
	.left     = 1491004800,
	.description = {
		"Master Information System as part as a double degree (English programme)",
		NULL
	}
};

school_t uni_fr = {
	.school   = "Ecole Nationale d'Ingenieur de Brest",
	.location = "Brest, France",
	.program  = "Engineering studies",
	.started  = 1283644800,
	.left     = 1401753600,
	.description = {
		"General engineering course and Engineer foundation studies",
		"Field of studies: IT,Electronics and Mecatronics",
		NULL
	}
};

school_t * schools[] = {
	&uni_ger,
	&uni_fr,
	NULL
};

/* Projects */
project_t blockchain = {
	.project = "Decentralized document management",
	.url     = "https://github.com/frenchieisverige/master-thesis",
	.title   = "Lead",
	.started = 1475280000,
	.left    = 1491004800,
	.description = {
		"A new way to send business documents by combining new upcoming technologies together such as blockchains (Ethereum) and decentralized storage (IPFS)",
		NULL
	}
};

project_t hfr = {
	.project = "Maintening Linx posts on the french forum Hardware.fr",
	.url     = "https://github.com/frenchieisverige/hfr-topics",
	.title   = "hfr-topics",
	.started = 1385856000,
	.left    = CURRENT,
	.description = {
		"Answering to people's questions related to the Linux world",
		NULL
	}
};

project_t * projects[] = {
	&blockchain,
	&hfr,
	NULL
};

/* Employment History */

job_t atr = {
	.company  = "atr Software GmbH",
	.location = "Neu Ulm, Germany",
	.title    = "Software Engineer",
	.started  = 1496275200,
	.left     = CURRENT,
	.description = {
		"Design, development, deployment and maintenance of Web-Apps with Angular, Typescript, HTML5, CSS5 an Docker",
		"Development and maintenance of software owned by the company EOS GmbH in C++/C#",
		NULL
	}
};

job_t * jobs[] = {
	&atr,
	NULL
};

void print_thing(thing_t * thing) {
	char started[100];
	char left[100];
	struct tm * ti;

	printf("%s at %s - %s\n", thing->title, thing->company, thing->location);

	ti = localtime(&thing->started);
	strftime(started, sizeof(started), "%B %d, %Y", ti);

	if (thing->left == CURRENT)  {
		printf("%s to now\n", started);
	} else {
		ti = localtime(&thing->left);
		strftime(left, sizeof(left), "%B %d, %Y", ti);
		printf("%s to %s\n", started, left);
	}

	const char ** desc;
	for (desc = thing->description; *desc; desc++) {
		printf("- %s\n", *desc);
	}

	puts("");
}

int main(int argc, char ** argv) {

	school_t ** s;
	job_t ** j;
	project_t ** p;

	printf("%s\n%s\n%s\n\n", name, email, address);

	puts("Education\n");
	for (s = schools; *s; s++) {
		print_thing(*s);
	}

	puts("Employment\n");
	for (j = jobs; *j; j++) {
		print_thing(*j);
	}

	puts("Projects\n");
	for (p = projects; *p; p++) {
		print_thing(*p);
	}

	return 0;
}