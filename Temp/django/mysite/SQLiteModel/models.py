from django.db import models
from django.contrib import admin

class site(models.Model):
    title = models.CharField(max_length = 150)
    body  = models.TextField()
    timestamp = models.DateTimeField()
    class Meta:
        ordering = ['-timestamp']