from django.db import models

# Create your models here.

class Event(models.Model):
    title = models.CharField(max_length=200)              # Название события
    location = models.CharField(max_length=200)           # Место проведения
    date = models.DateField()                             # Дата события
    start_time = models.TimeField()                       # Время начала
    is_free = models.BooleanField(default=False)          # Бесплатное или платное 
    ticket_price = models.DecimalField(max_digits=6, decimal_places=2, null=True, blank=True)  # Цена билета

    def __str__(self):
        return self.title
