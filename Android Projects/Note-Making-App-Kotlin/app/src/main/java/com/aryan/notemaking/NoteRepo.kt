package com.aryan.notemaking

import androidx.lifecycle.LiveData

class NoteRepo(private val noteDao: NoteDao) {

    val allNotes : LiveData<List<Notes>> = noteDao.getAllNotes()

    suspend fun insert(notes: Notes){
        noteDao.insert(notes)
    }

    suspend fun delete(notes: Notes){
        noteDao.delete(notes)
    }

}