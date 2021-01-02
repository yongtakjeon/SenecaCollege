/* Add any JavaScript you need to this file. */
/*Yongtak Jun, yjun4@myseneca.ca*/

window.onload = function () {
  function home() {
    document.querySelector('#n').setAttribute('style', 'display:block;');
    document.querySelector('#t').setAttribute('style', 'display:block;');
  }

  function hideTrending() {
    document.querySelector('#n').style.display = 'block';
    document.querySelector('#t').style.display = 'none';
  }

  function hideNew() {
    document.querySelector('#n').style.display = 'none';
    document.querySelector('#t').style.display = 'block';
  }
  document.querySelector('#menu1').addEventListener('click', home);
  document.querySelector('#menu2').addEventListener('click', hideTrending);
  document.querySelector('#menu3').addEventListener('click', hideNew);


  document.querySelector('#ordernum').style.display = 'none';
  function showInputbox() {
    document.querySelector('#ordernum').style.display = 'block';
    document.querySelector("#error").innerHTML = "";
  }
  function hideInputbox() {
    document.querySelector('#ordernum').style.display = 'none';
    document.querySelector("#error").innerHTML = "";
  }

  document.form1.asking[0].addEventListener('click', hideInputbox);
  document.form1.asking[1].addEventListener('click', hideInputbox);
  document.form1.asking[2].addEventListener('click', showInputbox);
};

function validation() {

  var checked = false;
  var err = document.querySelector("#error");

  for (var i = 0; i < 3; i++) {
    if (document.form1.asking[i].checked) {
      checked = true;
    }
  }
  if (!checked) {
    err.innerHTML = "Please make a selection.";
  }

  var input1 = document.form1.orderNo.value.trim();

  if (document.form1.asking[2].checked && input1.length == 0) {
    err.innerHTML = "Please enter the order number."
    return false;
  }
  return checked;
}
