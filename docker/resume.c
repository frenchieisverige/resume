#include <stdio.h>
#include <time.h>

typedef struct {
	union {
		const char * company;
		const char * school;
		const char * project;
		const char * masterthesis;
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
typedef thing_t masterthesis_t;

#define CURRENT 0 /* I wasn't alive at the Unix epoch, so that'll work */

/* Contact Information */
const char * name    = "Emmanuel SCHWARTZ";
const char * email   = "schwartz@mail.hs-ulm.de";
const char * hobbies = "Saxophone, IT Technology, Running, Travel, Cycling, Cars&Trucks";
const char * address = "89077 - Ulm\n"
                       "Germany";

/* Education */
school_t uni_ger = {
	.school   = "University Applied of Science",
	.location = "Ulm, Germany",
	.program  = "Master Information Systems",
	.started  = 1412467200,
	.left     = CURRENT,
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

/*Master Thesis*/

masterthesis_t mt_all = {
	.school   = "University Applied of Science",
	.location = "Ulm, Germany",
	.program  = "Master Information Systems",
	.started  = 1412467200,
	.left     = CURRENT,
	.description = {
		"PPC: Document wallet using decentralized document providers such as IPFS and StorJ and blokchains in order to store links.",
		NULL
	}
};

masterthesis_t * masterthesis[] = {
	&mt_all,
	NULL
};

/* Employment History */

job_t infosim_internship = {
	.company  = "Infosim GmbH & Co. KG",
	.location = "Wuerzburg, Germany",
	.title    = "Software Engineering Intern",
	.started  = 1456790400,
	.left     = 1468108800,
	.description = {
		"Architecture and Design Concepts for the Migration of a Java Rich Client to a Web Application",
		"Improvement of functionalities of a web application by external system access",
		NULL
	}
};

job_t dga_internship = {
	.company  = "DGA",
	.location = "Cazaux, France",
	.title    = "Techician Intern",
	.started  = 1370131200,
	.left     = 1377302400,
	.description = {
		"Technical writing of a datasheet about the STANAG 4609", 
		"Beginning of a C# program which can read 4609 data through the video.",
		NULL
	}
};

job_t * jobs[] = {
	&infosim_internship,
	&dga_internship,
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
	masterthesis_t ** mt;

	printf("%s\n%s\n%s\n\n", name, email, hobbies, address);

	puts("Education\n");
	for (s = schools; *s; s++) {
		print_thing(*s);
	}

	puts("Employment\n");
	for (j = jobs; *j; j++) {
		print_thing(*j);
	}

	puts("Master Thesis\n");
	for (mt = masterthesis; *mt; mt++) {
		print_thing(*mt);
	}

	return 0;
}
