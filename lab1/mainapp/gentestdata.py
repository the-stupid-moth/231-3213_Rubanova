import random, string, datetime
from .models import *
from django.db import transaction
import faker
from faker import Faker

fk = Faker()

def gentestdata():
    with transaction.atomic():
        for i in range(1000):
            new_event = Event()
            new_event.title = fk.sentence(nb_words=5)  # Генерируем случайное название события
            new_event.location = fk.city()  # Генерируем случайный город
            new_event.date = fk.date_between(
                start_date=datetime.date(2024, 1, 1),
                end_date=datetime.date(2025, 12, 31)
            )
            new_event.start_time = fk.time_object()  # Случайное время

            new_event.is_free = random.random() > 0.5  # 50% событий бесплатные

            if new_event.is_free:
                new_event.ticket_price = None  # Бесплатные события — цена пустая
            else:
                new_event.ticket_price = round(random.uniform(500, 5000), 2)  # Цена от 500 до 5000

            new_event.save()

    print('OK gentestdata()')