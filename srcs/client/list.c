#include "client.h"

t_data    *data_create(const char *buffer, int len)
{
    t_data *new;

    new = (t_data*)malloc(sizeof(t_data));
    if (!new)
        return (NULL);
    new->line = (char*)malloc(len + 1);
    if (!new->line)
        return (NULL);
    ft_memcpy(new->line, buffer, len);
    new->len = len;
    new->next = NULL;
    return (new);
}

void data_push(t_data **data, t_data *chunk)
{
    t_data *tmp;

    if (*data == NULL)
        *data = chunk;
    else
    {
        tmp = *data;
        while (tmp != NULL)
            tmp = tmp->next;
        tmp->next = chunk;
    }
}

void data_add(t_data **data, const char *buffer, int len)
{
    t_data *tmp;

    if (*data == NULL)
        *data = data_create(buffer, len);
    else
    {
        tmp = *data;
        while (tmp->next !=NULL)
            tmp = tmp->next;
        tmp->next = data_create(buffer, len);
    }
}

void data_free(t_data **data)
{
    t_data *tmp;
    t_data *prev;

    prev = NULL;
    tmp = *data;
    while (tmp != NULL)
    {
        free(tmp->line);
        prev = tmp;
        free(tmp);
        tmp = prev->next;
    }

}
