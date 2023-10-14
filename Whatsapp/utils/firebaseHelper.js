// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
export const getFirebaseApp = () => {
  const firebaseConfig = {
    apiKey: "AIzaSyADGACPOb0PuAWyRNy3d2D6wzNaExWi1Yo",
    authDomain: "whatsapp-81bec.firebaseapp.com",
    projectId: "whatsapp-81bec",
    storageBucket: "whatsapp-81bec.appspot.com",
    messagingSenderId: "311399104927",
    appId: "1:311399104927:web:e136fcc7355d394093fdaa",
    measurementId: "G-RHWN1Q1283",
  };

  // Initialize Firebase
  return initializeApp(firebaseConfig);
};
