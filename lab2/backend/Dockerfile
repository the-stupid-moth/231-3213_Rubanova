# базовый образ
FROM python:3.11-slim

# переменные окружения
ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1

# рабочая директория
WORKDIR /app

# зависимости
COPY requirements.txt /app/
RUN pip install --no-cache-dir -r requirements.txt

# копируем исходник
COPY . /app/

# gunicorn слушает 8000
CMD ["gunicorn", "core.wsgi:application", "--bind", "0.0.0.0:8000"]
