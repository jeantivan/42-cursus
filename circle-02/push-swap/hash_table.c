#include "hash_table.h"
#include "libft/libft.h"

unsigned int	hash(const char *key)
{
	unsigned long int	hash;
	int					i;

	i = 0;
	while (key[i])
	{
		hash = hash * 31 + key[i];
		i++;
	}
	return (hash % TABLE_SIZE);
}

HashTable	*create_table(int size)
{
	int			i;
	int			n;
	HashTable	*table;

	table= (HashTable *)malloc(sizeof(HashTable));
	if (!table)
		return (NULL);
	n = size;
	if (size > TABLE_SIZE)
		n = TABLE_SIZE;
	table->size = n;
	table->buckets = (Node **)malloc(sizeof(Node *) * n);
	if(!table->buckets)
		return (ft_safe_free((void **)&table));
	i = 0;
	while (i < n)
	{
		table->buckets[i] = NULL;
		i++;
	}
	return (table);
}

void insert(HashTable *table, const char *key, int value)
{
	unsigned int	index;
	Node			*node;
	//Node			*current;

	index = hash(key);
	node = (Node *)malloc(sizeof(Node));
	if(!node)
		return ;
	node->key = ft_strdup(key);
	node->value = value;
	node->next = table->buckets[index];
	table->buckets[index] = node;
}

int search(HashTable *table, const char *key)
{
	unsigned int	index;
	Node			*current;

	index = hash(key);
	current = table->buckets[index];
	while (current != NULL)
	{
		if(ft_strncmp(current->key, key, ft_strlen(key) == 0))
			return current->value;
		current = current->next;
	}
	return (-1);
}

void	free_map(HashTable *table)
{
	int	i;
	Node	*current;
	Node	*temp;

	i = 0;
	while (i < table->size)
	{
		current = table->buckets[i];
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			ft_safe_free((void **)&(temp->key));
			ft_safe_free((void **)&temp);
		}
		free(table->buckets);
		free(table);
	}
}
