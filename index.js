var mainText = document.getElementById("mainText");
var submitBtn = document.getElementById("submitBtn");




function submitClick() {

    var firebaseRef = firebase.database().ref();

    firebaseRef.child("Name").set(x);
}

function getValue() {
    var isChecked = document.getElementById("myCheckBox").checked;

    var firebaseRef = firebase.database().ref();

    if (isChecked) {
        firebaseRef.child("led1").set(1);

    } else {
        firebaseRef.child("led1").set(0);


    }
}

function getValue2() {
    var isChecked2 = document.getElementById("myCheckBox2").checked;
    var firebaseRef = firebase.database().ref();
    if (isChecked2) {
        firebaseRef.child("led2").set(1);

    } else {
        firebaseRef.child("led2").set(0);


    }
}