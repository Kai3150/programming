window.onload = function () {

  const box = document.querySelectorAll(".box");

  box.forEach(function (element) {
    element.style.width = "300px";
    element.style.height = "200px";
    element.style.border = "solid 1px black";
  })


  let obj1 = { name: "tanaka", age: 11 };
  console.log(obj1);

  function Person(name, age) {
    this.name = name;
    this.age = age;
  }

  const person = new Person("inoue", 33);
  console.log(person);


  let target = null;


  let drag = document.getElementById('drag');

  // drag側
  drag.ondragstart = function (e) {
    target = e.target;

    console.log(e.target);
  }

 // 非表示
  drag.ondrag = function (e) {
    drag.style.display = "none";
  }

  // drop側
  document.ondragover = function (e) {
    e.preventDefault();
  }

  document.ondrop = function (e) {
    e.preventDefault();
    if (e.target.id == 'drop') {
      console.log(e.target);
      e.target.appendChild(target);
    }

    drag.style.display = 'block';
  }

  const geo = document.getElementsByClassName("geo")[0]
  navigator.geolocation.getCurrentPosition(suc);
  function suc(position) {
    geo.insertAdjacentHTML("beforeend", "経度" + position.coords.latitude + "<br>");
    geo.insertAdjacentHTML("beforeend", "緯度" + position.coords.longitude);
  }

  
}
