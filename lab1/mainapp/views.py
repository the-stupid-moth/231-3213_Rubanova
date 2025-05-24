from django.conf import settings
from rest_framework import viewsets
from rest_framework.response import Response

from .models import Event
from .serializers import EventSerializer

class EventViewSet(viewsets.ModelViewSet):
    queryset = Event.objects.all()
    serializer_class = EventSerializer

    def create(self, request, *args, **kwargs):    # HTTP POST /event/
        return super().create(request, *args, **kwargs)

    def retrieve(self, request, *args, **kwargs):  # HTTP GET  /event/{pk}/
        return super().retrieve(request, *args, **kwargs)

    def update(self, request, *args, **kwargs):    # HTTP PUT  /event/{pk}/
        return super().update(request, *args, **kwargs)

    def destroy(self, request, *args, **kwargs):   # HTTP DELETE /event/{pk}/
        return super().destroy(request, *args, **kwargs)

    def list(self, request, *args, **kwargs):      # HTTP GET   /event/
        return super().list(request, *args, **kwargs)
