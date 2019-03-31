from django.shortcuts import render,redirect
from .models import Name
# Create your views here.
def index(request):
	name = Name.objects.all()
	context = {'name':name}
	return render(request,'index.html',context)

def create(request):
	name = Name(fname = request.POST['fname'],
				lname = request.POST['lname'])
	name.save()
	return redirect('/')

def delete(request,id):
	name = Name.objects.get(id=id)
	name.delete()
	return redirect('/')

def edit(request,id):
	name = Name.objects.get(id=id)
	context = {'name':name}
	return render(request,'edit.html',context)

def update(request,id):
	name = Name.objects.get(id=id)
	name.fname = request.POST['fname']
	name.lname = request.POST['lname']
	name.save()
	return redirect('/')