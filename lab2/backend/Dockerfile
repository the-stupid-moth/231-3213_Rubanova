# 1. Базовый образ
FROM python:3.11-slim

# 2. Переменные окружения
ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1

# 3. Рабочая директория в образе
WORKDIR /app

# 4. Копируем и ставим зависимости
COPY requirements.txt /app/
RUN pip install --no-cache-dir -r requirements.txt

# 5. Копируем весь исходник
COPY . /app/

# 6. По желанию: соберите статику
# RUN python manage.py collectstatic --noinput

# 7. Точка входа (gunicorn слушает 8000)
CMD ["gunicorn", "core.wsgi:application", "--bind", "0.0.0.0:8000"]
