document.getElementById('verifyBtn').addEventListener('click', function() {
  const password1 = document.getElementById('password1').value;
  const password2 = document.getElementById('password2').value;

  if (password1.length < 8 || password2.length < 8) {
    alert("Both passwords must be at least 8 characters long.");
  } else if (password1 !== password2) {
    alert("Passwords do not match.");
  } else {
    alert("Passwords matched!");
  }
});

