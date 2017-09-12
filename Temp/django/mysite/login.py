from django.shortcuts import render
from django.views.decorators import csrf
from django.http import HttpResponse
from django.shortcuts import render_to_response

def login(username,password):



def login_form(request):
    ctx ={}
    if request.POST:
        login(username,password)
    return render(request, "login.html", ctx)
