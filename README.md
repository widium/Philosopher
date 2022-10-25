# Philosopher
## Theorie
- ### [Threads](#threads)
- ### [Mutex](#mutex)
- ### [Time](#time)

## Pratique
- ### [Data Structure](#data-structure)
- ### [Supervisor](#supervisor)
- ### [Delayed Start](#delayed-start)
- ### [Cycle of Philo](#cycle-of-philo)
***
![](https://i.imgur.com/CMD7w60.png)
***
# Threads

~~~C
#include <pthread.h>
compile with -pthread
~~~
## Creer un Thread
#### **Creer** une struct `pthread_t`
~~~C
pthread_t t1;
~~~

#### **Creer** une fonction a executer 
- cette fonction doit :
	- retourner un `void *`
	- prendre un `void *` en argument
~~~C
void *routine(void *arg)
{
	printf("Thread\n");
	return (NULL);
}
~~~
#### **Creer** le thread avec :
- **L'adresse** de la structure `pthread_t`
- les **options** ici : `NULL`
- la **fonction** a executer
- un `void *` sur ses **arguments** :
~~~C
char *test = "hello world";

pthread_create(&t1, NULL, routine, test);
~~~

#### **Attendre** que le Thread s'execute :
~~~C
pthread_join(t1, NULL);
~~~

### *Exemple complet* 
~~~C
void *routine(void *text)
{
	printf("Thread [%s]\n", (char *)text);
	sleep(2);
	printf("Thread finish\n");
	return (NULL);
}


int	init_thread(void)
{
	pthread_t t1;
	pthread_t t2;
	char *test = "hello world";
	char *test2 = "goodbye world";
	
	pthread_create(&t1, NULL, &routine, test);
	pthread_create(&t2, NULL, &routine, test2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}

>>
hello world
goodbye world

Thread finish
Thread finish
~~~
***
# Mutex

### *Forcer plusieurs threads a attendre avant d'acceder a une valeur :*


- Creer un verrou qui :
	- forcerait les autres threads à **attendre** que le thread actuel termine l’exécution 
	- qui **bloque** l'acces a la varaible le temps qu'il finissent de s'executer

### Initialiser un Mutex :

- **Declarer** un `pthread_mutex_t`
- Passer l'**adresse** du mutex avec `NULL` comme argument;
~~~C
pthread_mutex_t mutex;
pthread_mutex_init(&mutex, NULL);
~~~

### Bloquer l'acces aux valeur et faire attendre les autre threads

- Utiliser les 2 fonction **entre le code a proteger** aux donnant **l'adresse du Mutex** 
~~~C
pthread_mutex_lock(&mutex);
//lock value
pthread_mutex_unlock(&mutex);
~~~

### Detruire le Mutex

- **Apres l'execution des thread detruire le mutex** avec la fonction `pthread_mutex_destroy(&mutex)` qui prend l'adresse du mutex en parametres.
~~~C
pthread_mutex_destroy(&mutex)
~~~

### Example  

~~~C
int number = 0;
pthread_mutex_t mutex;

void *routine(void *text)
{
	(void)text;
	pthread_mutex_lock(&mutex);
	printf("Thread increment [%d]\n", number);
	number++;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}


int	init_thread(void)
{
	pthread_t t1;
	pthread_t t2;
	
	pthread_mutex_init(&mutex, NULL);
	printf("number before : [%d]\n", number);
	pthread_create(&t1, NULL, routine, NULL);
	pthread_create(&t2, NULL, routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("number after : [%d]\n", number);
	pthread_mutex_destroy(&mutex);
	return (0);
}
~~~
***
# Time
## *intialiser une Struct `Timeval`* 
- `tv_sec` Donne **le nombre de seconde ecouler** depuis le **1/1/1970**
- `tv_usec` Donne **le nombre de microseconde ecouler** apres le nombre de seconde depuis **1/1/1970** **(une precision Suplementaire !)**
~~~C
struct timeval 
{
   time_t      tv_sec;   // Number of whole seconds of elapsed time
   long int    tv_usec;  // Number of microseconds of rest of elapsed time
};
~~~
### *Utiliser la Fonction `gettimeofday()`*
- Donner l'adresse de la struct `timeval`
- Donner `NULL` en argument 
~~~C
gettimeofday(&current_time, NULL);
~~~
### Convertir les Seconde et les Microseconde en Milliseconde
- **Multiplier** les seconde par `1000`
- **Diviser** les Microseconde par `1000`
- **Additionner** les 2 une fois sur la meme echelles ;)
~~~C
seconde = seconde_to_milliseconde(current_time.tv_sec);
microseconde = microseconde_to_milliseconde(current_time.tv_usec);
time = seconde + microseconde;
~~~
### *Get_time() function*
~~~C
long int    get_actual_time(void)
{
    long int        time;
    long int        seconde;
    long int        microseconde;
    struct timeval  current_time;
    
    gettimeofday(&current_time, NULL);
    seconde = seconde_to_milliseconde(current_time.tv_sec);
    microseconde = microseconde_to_milliseconde(current_time.tv_usec);
    time = seconde + microseconde;
    return (time);
}

time = get_actual_time()
printf("current time %ldms\n", time);

1666022660728ms
~~~
- **Recuperer** le start_time avec Get_actual_time Milliseconde 
- **Definir** un timer en milliseconde avec le temps qui passe Get_time_pass 
- **Tant** que le Timer n'est pas fini :
	- **Calculer** le temps qui reste
	- Sleep  Usleep 
~~~C
void milliseconde_sleep(long int milliseconde)
{
    long int	start_time;
    long int    timer_ms;

	start_time = get_actual_time();
    timer_ms = get_time_pass(start_time, get_actual_time());
	while (timer_ms < milliseconde)
    {
        timer_ms = get_time_pass(start_time, get_actual_time());
        usleep(milliseconde / 1000);
    }
		
}

long int	get_time_pass(long int start, long int end)
{
	return (end - start);
}
~~~

### *tester avec la fonction original :*
- avec Get_time_pass  on peut tester les fonction :
- 
~~~C
start = get_actual_time();
milliseconde_sleep(2000);
printf("time pass [%ldms]\n", get_time_pass(start, get_actual_time()));
~~~
***
# Data Structure
![](https://i.imgur.com/9FEQPNb.png)
![](https://i.imgur.com/AttJZvS.png)
![](https://i.imgur.com/ppSzvnk.png)

- Chaque Philo dispose :
	- D'un **Index** sur la table
	- D'un **state** 
	- D'une **fourchette** a lui
	- D'un **Pointeur sur la fourchette de son voisin**
~~~C
typedef	struct s_philo
{
    int             num;
	int             state;
    pthread_mutex_t fork;
    pthread_mutex_t *next_fork;
    t_times        *times;
    pthread_t       thread;
    struct s_philo  *next;
    struct s_philo  *prev;

}   t_philo;
~~~

### Pointeur de Fourchette
- Si on **affiche les adresse de** :
	- *La fourchette du philo* 
	- *La fourchette de son voisin* 
- On peut remarquer les ardresse similaire entre :
  - **le pointeur** sur *la fourchette de son voisin*
  - *la fourchette de son voisin* 
Ex : 
~~~C
---- Philo Num : [0] ----
Fork [0x608000000028]
Next Fork [0x6080000000a8]
State : [NULL]
----- ----- -----
---- Philo Num : [1] ----
Fork [0x6080000000a8]
Next Fork [0x608000000128]
State : [NULL]
----- ----- -----
~~~
#### Donner l'adresse de la fourchette de son voisin :
- **Bouclez** dans tant qu'il n'y a pas de next philo
	- **Faire** **Pointer** `next_fork` sur l'adresse de la fourchette du prochain philo
	- **Arriver** aux dernier philo 
	- **Recuperer** le premier philo
	- **Faire Pointer** le`next_fork` du **dernier philo** sur l'adresse de **la fourchette du premier philo**
~~~C
void give_fork_at_philo(t_env *env)
{
    t_philo *philo;
    t_philo *first_philo;

    philo = get_first_philo(env);
    while (philo->next)
    {
        philo->next_fork = &philo->next->fork;
        philo = philo->next;
    }
    first_philo = get_first_philo(env);
    philo->next_fork = &first_philo->fork;
}
~~~
#### List Complete de philosopher
- On peut remarquer que **le dernier philo** **pointe** sa `next_fork` sur **la fourchette du premier philo** !
~~~C
----------------
---- Philo Num : [0] ----
Fork [0x608000000028]
Next Fork [0x6080000000a8]
State : [NULL]
----- ----- -----
---- Philo Num : [1] ----
Fork [0x6080000000a8]
Next Fork [0x608000000128]
State : [NULL]
----- ----- -----
---- Philo Num : [2] ----
Fork [0x608000000128]
Next Fork [0x6080000001a8]
State : [NULL]
----- ----- -----
---- Philo Num : [3] ----
Fork [0x6080000001a8]
Next Fork [0x608000000028]
State : [NULL]
----- ----- -----

~~~
***
# Supervisor

![](https://i.imgur.com/NSdi51y.png)

### Supervisor Donne la mort ou la vie sauve
- Le supervisor represente le Process  principale qui a creer tous les Thread.
- Le principe est simple , lorsque tous les threads on ete creer avec un Thread `pthread_create` on n'as pas utiliser la fonction `pthread_join` qui permet d'attendre leur execution
- Ce qui permet de pouvoir **les terminer quand on veut** 
- Le but est donc de creer **une boucle infinie qui test en permanence les information de chaque threads comme** :
	- Est ce qu'il **reste assez de temps** a chaque philo **avant de mourrir de faim**
	- Est ce qu'il **ont assez manger**
	- Est ce qu'il y a **des philo mort ?**
	- Est ce que **tous le monde a assez manger ?**
- quand **il finit de checker il decide si le philo meurt ou tous le monde s'en sort indeme**
A la fin de la loop on laisse finir les threads pour eviter un Dead-Lock , sans qu'il peuvent faire une actions
~~~C
philo = get_first_philo(table);
while (1)
{
	if (philo_have_no_more_time_to_eat(philo) && have_not_eat_enough(philo))
	{
		philo_die(philo);
		break ;
	}
	else if (there_are_not_dead_philos(table)
		&& all_philo_have_eat_enough(table))
	{
		printf("Each philo eat [%d] time(s)\n", table->times->number_of_meals);
		break ;
	}
	philo = philo->next;
	get_infinite_loop(table, &philo);
}
protect_finish_thread(table);
~~~
***
# Delayed Start
![](https://i.imgur.com/tHTm1RG.png)

~~~C
void	create_delayed_start(t_philo *philo)
{
	if (philo_is_impair(philo))
	{
		ms_sleep(philo->times->eat_time / 2);
	}
}
~~~
***
# Cycle of Philo 


![](https://i.imgur.com/RCbhXIy.png)

- **Commencer** avec un [[Delayed Start - Philosopher]]
- **Check** La table 
- **Recuperer** 2 Fourchette
- **Manger**
- **Dormir**
- **Penser** 
~~~C
int	philo_can_make_action(t_philo *philo)
{
	if (there_are_not_dead_philos(philo->table) && have_not_eat_enough(philo))
		return (1);
	return (0);
}

void	*cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	create_delayed_start(philo);
	while (1)
	{
		if (philo_can_make_action(philo))
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		else
			break ;
	}
	return (NULL);
}

void	change_state(t_philo *philo, int state)
{
	philo->state = state;
}

void	philo_eat(t_philo *philo)
{
	if (philo_can_use_two_fork(philo))
	{
		if (philo_can_make_action(philo))
		{
			change_state(philo, EAT);
			print_philo_state(philo);
			reset_eat_timer(philo);
			update_meal_counter(philo);
			ms_sleep(philo->times->eat_time);
		}
	}
	philo_puts_down_fork(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (philo_can_make_action(philo))
	{
		change_state(philo, SLEEP);
		print_philo_state(philo);
		ms_sleep(philo->times->sleep_time);
	}
}

void	philo_die(t_philo *philo)
{
	if (philo_can_make_action(philo))
	{
		philo->table->philo_dead += 1;
		change_state(philo, DEAD);
		print_philo_state(philo);
	}
}

void	philo_think(t_philo *philo)
{
	if (philo_can_make_action(philo))
	{
		change_state(philo, THINK);
		print_philo_state(philo);
	}
}

~~~
