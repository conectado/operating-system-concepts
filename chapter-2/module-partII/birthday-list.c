#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

struct birthday *person;

void print_birthday(struct birthday bday) 
{
  printk(KERN_INFO "Birthday day %d month %d year %d", bday.day, bday.month, bday.year);
}

struct birthday *birthday_create(int day, int month, int year) 
{
  struct birthday *temp;
  temp = kmalloc(sizeof(*temp), GFP_KERNEL);
  temp->day = day;
  temp->month = month;
  temp->year = year;

  return temp;
}

void init_birthday_list(struct birthday *p) 
{
  p = birthday_create(13, 7, 1993);
  INIT_LIST_HEAD(&p->list);
}


void add_birthday_items(struct birthday *p)
{
  list_add_tail(&birthday_create(10, 8, 1990)->list, &p->list);
  list_add_tail(&birthday_create(2, 4, 1994)->list, &p->list);
  list_add_tail(&birthday_create(11, 1, 1996)->list, &p->list);
  list_add_tail(&birthday_create(6, 2, 1992)->list, &p->list);
  list_add_tail(&birthday_create(21, 3, 1995)->list, &p->list);
}

void print_items(struct birthday *p)
{
  struct birthday *ptr;
  list_for_each_entry(ptr, &p->list, list) {
    print_birthday(*ptr);
  }
}

void destroy_birthday_items(struct birthday *p) 
{
  struct birthday *ptr, *next;
  list_for_each_entry_safe(ptr, next, &p->list, list) {
    list_del(&ptr->list);
    kfree(ptr);
  }
}

/* This function is called when the module is loaded. */
int simple_init(void)
{
  printk(KERN_INFO "Loading Module\n");

  init_birthday_list(person);
  add_birthday_items(person);
  print_items(person);

  return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void)
{
  printk(KERN_INFO "Removing module\n");
  destroy_birthday_items(person);
}

/* Macros for registering module entry and exit point. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Birthday Module");
MODULE_AUTHOR("conectado");
