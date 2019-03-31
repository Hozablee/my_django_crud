"""my_app URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from django.conf.urls import url
from my_app1 import views
urlpatterns = [
    path('admin/', admin.site.urls),
    url(r'^$',views.index),
    url(r'^create$',views.create),
    url(r'^delete/(?P<id>\d+)$',views.delete),
    url(r'^edit/(?P<id>\d+)$',views.edit),
    url(r'^edit/update/(?P<id>\d+)$',views.update),
]
