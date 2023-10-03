document.querySelector("#burger-menu").addEventListener("click", () => {
  const menu = document.querySelector(".menu")
  menu.querySelectorAll("a").forEach((a) => {
    a.style.display = a.style.display === "" ? "flex" : ""
  })
  document.querySelector("#burger-menu").style.alignSelf = "flex-end"
})
