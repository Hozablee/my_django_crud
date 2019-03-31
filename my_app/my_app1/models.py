from django.db import models

# Create your models here.
class Name(models.Model):
	fname = models.CharField(max_length=40)
	lname = models.CharField(max_length=40)
	def __str__(self):
		return fname+' '+lname