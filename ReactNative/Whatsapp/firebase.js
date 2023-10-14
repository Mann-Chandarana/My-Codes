// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
import {createUserWithEmailAndPassword, getAuth, signInWithEmailAndPassword} from 'firebase/auth';
import {getStorage} from 'firebase/storage';
import {initializeFirestore} from 'firebase/firestore';

const firebaseConfig = {
  apiKey: "AIzaSyCjpDdaNhxeBt6blNr3H_zDPn6f-IA6cqw",
  authDomain: "whatsapp-clone-ea8cb.firebaseapp.com",
  projectId: "whatsapp-clone-ea8cb",
  storageBucket: "whatsapp-clone-ea8cb.appspot.com",
  messagingSenderId: "115297915022",
  appId: "1:115297915022:web:1555fcb4e1e9b098d539df",
  measurementId: "G-C8ZFM8TEB9"
};

// Initialize Firebase
export const app = initializeApp(firebaseConfig);
export const auth = getAuth(app);
export const storage = getStorage(app);
const analytics = getAnalytics(app);
export const db = initializeFirestore(app,{
    experimentalForceLongPolling:true,
});

export function signIn(email,password){
    return signInWithEmailAndPassword(auth,email,password);
}

export function signUp(email,password){
    return createUserWithEmailAndPassword(auth,email,password);
}