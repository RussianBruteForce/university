#include "functions.h"

List *createL()
{
	List *buf = (List*) malloc(sizeof(List));
	buf->size = 0;
	buf->head = buf->tail = NULL;

	return buf;
}

void deleteL(List **l)
{
	Node *buf = (*l)->head;
	Node *next = NULL;
	while (buf) {
		next = buf->next;
		free(buf);
		buf = next;
	}
	free(*l);
	(*l) = NULL;
}

ErrorCode push_front(List *l, void *data)
{
	Node *buf = (Node*) malloc(sizeof(Node));
	if (buf == NULL)
		return BadMemory;

	buf->data = data;
	buf->next = l->head;
	buf->prev = NULL;
	if (l->head) //если первый элемент уже был, то заставляем его ссылаться на новый
		l->head->prev = buf;
	l->head = buf;

	if (l->tail == NULL) //если хвоста небыло, то теперь он должен ссылаться на объект
		l->tail = buf;
	l->size++;
	return (ErrorCode)NULL;
}

void *pop_front(List *l)
{
	if (l->head == NULL)
		return (void*)NoHead;

	Node *prev = l->head;
	l->head = l->head->next; //теперь начало сылается на след элемент
	if (l->head)
		l->head->prev = NULL; //если удачно, то сообщаем что предыдущего элемента не будет
	if (prev == l->tail) //если это все один элемент
		l->tail = NULL; //то сообщаем что хвоста тоже нет
	void *buf = prev->data;
	free(prev);

	l->size--;
	return buf;
}

ErrorCode push_back(List *l, void *data)
{
	Node *buf = (Node*) malloc(sizeof(Node));
	if (buf == NULL)
		return BadMemory;


	buf->data = data;
	buf->next = NULL;
	buf->prev = l->tail;
	if (l->tail)
		l->tail->next = buf;
	l->tail = buf;

	if (l->head == NULL)
		l->head = buf;
	l->size++;
	return (ErrorCode)NULL;
}

void *pop_back(List *l)
{
	Node *next;
	void *buf;
	if (l->tail == NULL)
		return (void*)NoTail;

	next = l->tail;
	l->tail = l->tail->prev;
	if (l->tail)
		l->tail->next = NULL;

	if (next == l->head)
		l->head = NULL;

	buf = next->data;
	free(next);

	l->size--;
	return buf;
}

Node *get_at(List *l, size_t at)
{
	Node *buf = l->head;
	size_t i = 0;

	while (buf && i < at) {
		buf = buf->next;
		i++;
	}

	return buf;
}

ErrorCode insert_at(List *l, size_t at, void *data)
{
	Node *elm = get_at(l, at); //находим элемент по индексу
	if (elm == NULL) {
		if (l->size == 0)
			return push_front(l, data);
		else
			return OutOfRange;
	}
	Node *ins = (Node*) malloc(sizeof(Node)); //создаем новый узел
	ins->data = data;
	//Меняем все адреса
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next)
		elm->next->prev = ins;

	elm->next = ins;

	if (!elm->prev)
		l->head = elm;
	if (!elm->next)
		l->tail = elm;

	l->size++;
	return (ErrorCode)NULL;
}

void *delete_at(List *l, size_t at)
{
	Node *elm = get_at(l, at);
	if (elm == NULL)
		return (void*)OutOfRange;

	if (elm->prev)
		elm->prev->next = elm->next;

	if (elm->next)
		elm->next->prev = elm->prev;

	void *tmp = elm->data;

	if (!elm->prev)
	l->head = elm->next;

	if (!elm->next)
		l->tail = elm->prev;

	free(elm);

	l->size--;
	return tmp;
}

void print_list(List *l, void (*print_function)(void *))
{
	Node *tmp = l->head;
	while (tmp) {
		print_function(tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void print_int(void *data)
{
	printf("%d ", *((int*) data));
}

void print_unsigned(void *data)
{
	printf("%u ", *((unsigned int*) data));
}

void print_char(void *data)
{
	printf("%c ", *((char*) data));
}

void print_string(void *data)
{
	printf("%s ", *((char**) data));
}

void *error_handler(void* error)
{
	switch ((ErrorCode)error) {
	case NoErrors:
		return "";
		break;
	case OutOfRange:
		return "Position is out of range!";
		break;
	case BadMemory:
		return "Can't allocate memory!";
		break;
	case NoHead:
		return "Can't find head. Is list empty?";
		break;
	case NoTail:
		return "Can't find tail. Is list empty?";
		break;
	default:
		return (void*)error;
		break;
	}
}


int summ_elements_from(List *l, size_t pos)
{
	int ret = 0;
	for (size_t i = pos; i < l->size; i++) {
		ret += *((int*)(get_at(l,i)->data));
	}
	return ret;
}
