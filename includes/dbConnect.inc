<?php 

// Als username en wachtwoord niet ingesteld zijn in het config bestand -- default naar "root" "root"
if (!isset($dbUsername) && !isset($dbPassword)) {
  $dbUsername = $dbPassword = "root";
}

if (!isset($dbName)) {
  $dbName = 'mijn_dagboek';
}

// Nieuwe database connectie aanmaken
$conn = new PDO("mysql:host=localhost;dbname=$dbName", $dbUsername, $dbPassword);
$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
